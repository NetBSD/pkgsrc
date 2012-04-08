# $NetBSD: Makefile,v 1.42.2.1 2012/04/08 09:19:03 sbd Exp $
#

DISTNAME=		sge-8.0.0d
PKGNAME=		sge-8.0.0.4
CATEGORIES=		parallel sysutils
MASTER_SITES=		http://arc.liv.ac.uk/downloads/SGE/releases/8.0.0d/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://arc.liv.ac.uk/trac/SGE
COMMENT=		Son of Grid Engine distributed resource management system

BUILD_DEPENDS+=		{standalone-tcsh,tcsh}-[0-9]*:../../shells/tcsh

PKG_DESTDIR_SUPPORT=	user-destdir

# Not 64-bit clean; crashes during build.
NOT_FOR_PLATFORM=	${LP64PLATFORMS}

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl:run

CFLAGS+=		-D${UPPER_OPSYS}
CONFIGURE_ENV+=		REMOTE=sge
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-sge=${SGE_BUILDARCH:Q}
PLIST_SUBST+=		SGE_ARCH=${SGE_ARCH:Q}
MESSAGE_SUBST+=		SGE_ROOT=${SGE_ROOT}
MAKE_ENV+=		PERL5=${PERL5:Q}

SGE_USER?=		sgeadmin
SGE_GROUP?=		sgeadmin
PKG_GROUPS=		${SGE_GROUP}
PKG_USERS=		${SGE_USER}:${SGE_GROUP}::Sun\ Grid\ Engine\ Administrator
PKG_GROUPS_VARS+=	SGE_GROUP
PKG_USERS_VARS+=	SGE_USER

EVAL_PREFIX+=	PKGSRC_SSL_PREFIX=openssl

AIMK=	${SETENV} ${MAKE_ENV} tcsh -fb ${WRKSRC}/source/aimk

CONFIG_GUESS_OVERRIDE=	source/3rdparty/qmake/config.guess \
		source/3rdparty/qtcsh/config.guess
CONFIG_SUB_OVERRIDE=	source/3rdparty/qmake/config.sub \
		source/3rdparty/qtcsh/config.sub

REPLACE_INTERPRETER+=	tclsh
REPLACE.tclsh.old=	.*tclsh
REPLACE.tclsh.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tclsh=	source/dist/util/resources/jsv/jsv.tcl
REPLACE_PERL+=		source/dist/util/resources/jsv/jsv.pl

CHECK_INTERPRETER_SKIP+=	sge/ckpt/cpr_* sge/mpi/myrinet/* sge/util/resources/loadsensors/interix-loadsensor.sh

.include "../../mk/bsd.prefs.mk"

# SGE_ARCH should match the putput of ${WRKSRC}/source/dist/util/arch
# SGE_BUILDARCH should match whats in ${WRKSRC}/source/aimk
UPPER_OPSYS_cmd=	${ECHO} "${OPSYS}" | ${TR} a-z A-Z
UPPER_OPSYS=		${UPPER_OPSYS_cmd:sh}

.if ${OPSYS} == "NetBSD"
AIMK+=			-DFD_SETSIZE=2048
SGE_ARCH=		nbsd-${MACHINE_ARCH}
SGE_BUILDARCH_cmd=	${ECHO} "${OPSYS}_${MACHINE_ARCH}" | ${TR} a-z A-Z
.elif ${OPSYS} == "FreeBSD"
SGE_ARCH=		fbsd-${MACHINE_ARCH}
SGE_BUILDARCH_cmd=	${ECHO} "${OPSYS}_${MACHINE_ARCH}" | ${TR} a-z A-Z
.elif ${OPSYS} == "SunOS"
.  if ${MACHINE_ARCH} == "i386"
SGE_ARCH=		solaris86
.  else
_ISAINFO!=		isainfo
.    if !empty(_ISAINFO:Msparcv9)
SGE_ARCH=		solaris64
.    else
SGE_ARCH=		solaris
.    endif
.  endif
SGE_BUILDARCH_cmd=	${ECHO} "${SGE_ARCH}" | ${TR} a-z A-Z
.elif ${OPSYS} == "Darwin"
SGE_ARCH=		darwin
SGE_BUILDARCH=		DARWIN
.elif ${OPSYS} == "Linux"
AIMK+=			-no-dump
SGE_ARCH=		lx26-x86
SGE_BUILDARCH=		LINUX86
.else
PKG_FAIL_REASON+=	"SGE_ARCH and SGE_BUILDARCH need to be configured for your OS"
.endif
SGE_BUILDARCH?=		${SGE_BUILDARCH_cmd:sh}

# Some hacks to get it properly linked:
MAKE_ENV+=	SGE_ARCH=$(SGE_ARCH) SGE_ROOT=$(SGE_ROOT)

LDFLAGS+=	-R${SGE_ROOT}/lib/${SGE_ARCH}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${SGE_ROOT}/lib/${SGE_ARCH}

SGE_ROOT=	${PREFIX}/sge

INSTALLATION_DIRS=	bin

post-patch:
	@if [ "`${WRKSRC}/source/dist/util/arch`" != "${SGE_ARCH}" ]; then \
		${ECHO} "ERROR:  SGE_ARCH as set in the pkgsrc Makefile," ;\
		${ECHO} "        ${SGE_ARCH}, does not agree with that returned by" ; \
		${ECHO} "        ${WRKSRC}/source/dist/util/arch," ; \
		${ECHO} "        `${WRKSRC}/source/dist/util/arch`" ; \
		${FALSE} ; \
	fi
	( ${ECHO} "set OPENSSL_HOME = ${SSL_PREFIX}" ; \
	${ECHO} "set BERKELEYDB_HOME = ${BUILDLINK_PREFIX.db4}" ; \
	${ECHO} "set BDB_INCLUDE_SUBDIR = db4" ; \
	${ECHO} "set BDB_LIB_SUFFIX = 4" ; \
	${ECHO} "set PERL = ${PERL5}" ) > ${WRKSRC}/source/aimk.private
	( ${ECHO} "OPENSSLBASE=${SSL_PREFIX}" ; \
	${ECHO} "BERKELEYDBBASE=${BUILDLINK_PREFIX.db4}" ) > ${WRKSRC}/source/distinst.private

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	source/dist/util/arch_variables
SUBST_SED.paths=	-e 's;@rcd_dir@;${RCD_SCRIPTS_DIR};' 

do-configure:
.for __prog__ in qmake qtcsh
	${MKDIR} ${WRKSRC}/source/3rdparty/${__prog__}/${SGE_BUILDARCH}
	cd ${WRKSRC}/source/3rdparty/${__prog__}/${SGE_BUILDARCH} && \
		${SETENV} ${CONFIGURE_ENV} \
		SGE_ARCH=`${WRKSRC}/source/dist/util/arch` \
		../configure ${CONFIGURE_ARGS} --srcdir=..
.endfor

do-build:
	cd ${WRKSRC}/source && ${AIMK} -no-java -no-jni -only-depend
	cd ${WRKSRC}/source && ${SETENV} ${MAKE_ENV} ./scripts/zerodepend
	cd ${WRKSRC}/source && ${AIMK} -no-java -no-jni -no-qmake -no-qtcsh depend
	cd ${WRKSRC}/source && ${AIMK} -no-java -no-jni
	cd ${WRKSRC}/source && ${AIMK} -no-java -no-jni -man -sunman

CHECK_INTERPRETER_SKIP=	sge/bin/process-scheduler-log \
			sge/bin/qsched \
			sge/bin/status \
			sge/examples/drmaa/ruby/* \
			sge/hadoop/pestart.sh \
			sge/hadoop/pestop.sh \
			sge/hadoop/setup.pl \
			sge/hadoop/wait.sh \
			sge/util/resources/drmaa4ruby/* \
			sge/util/resources/drmaa4ruby/samples/* \
			sge/util/resources/wrappers/rshd-wrapper

do-install:
	${MKDIR} ${DESTDIR}${SGE_ROOT}
	#${CHOWN} ${SGE_USER} ${DESTDIR}${SGE_ROOT}
	#${CHGRP} ${SGE_GROUP} ${DESTDIR}${SGE_ROOT}
	cd ${WRKSRC}/source && \
		${ECHO} "Y" | ${SETENV} LOCALBASE=${LOCALBASE} DESTDIR=${DESTDIR} SGE_ROOT=${SGE_ROOT} ./scripts/distinst -local -all -nobdb -noopenssl -mansrc sge ${SGE_ARCH} -- doc man
	for f in archive checkpoint deadlock dump load printlog recover stat upgrade verify ; do \
		ln -s ${DESTDIR}${LOCALBASE}/bin/db4_$${f} ${DESTDIR}${SGE_ROOT}/utilbin/${SGE_ARCH}/db_$${f} ; done
	ln -s ${DESTDIR}${LOCALBASE}/bin/berkeley_db4_svc ${DESTDIR}${SGE_ROOT}/utilbin/${SGE_ARCH}/berkeley_db_svc
	ln -s ${DESTDIR}${SSL_PREFIX}/bin/openssl ${DESTDIR}${SGE_ROOT}/utilbin/${SGE_ARCH}/openssl
	cd ${DESTDIR}${SGE_ROOT} && ${SETENV} SGE_ROOT=${SGE_ROOT} DESTDIR=${DESTDIR} ./util/setfileperm.sh -auto \
		${SGE_ROOT}
	for f in ${DESTDIR}${SGE_ROOT}/bin/${SGE_ARCH}/q* ; do \
		cd ${DESTDIR}${PREFIX}/bin && ln -fs $$f ; done

#% scripts/distinst -local"

PLIST_SUBST+=	SGE_ARCH=${SGE_ARCH}

.include "../../databases/db4/buildlink3.mk" # 4.2 at least
.include "../../x11/Xbae/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.if ${USE_BUILTIN.openssl} == "yes"
SSL_PREFIX=	/usr
.else
SSL_PREFIX=	${PKGSRC_SSL_PREFIX}
.endif
