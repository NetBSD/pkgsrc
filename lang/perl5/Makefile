# $NetBSD: Makefile,v 1.41 2001/09/06 17:33:50 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		perl-${PERL5_VERS}
PERL5_PKG_VERS=		nb2
CATEGORIES+=		lang devel

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		Practical Extraction and Report Language

CONFLICTS=		perl-5.00* perl-base-[0-9]* \
			p5-CGI-2.66 p5-CGI-2.75 p5-CGI-2.75.[0-2] \
			p5-Data-Dumper-2.1[0-9][0-9] p5-Data-Dumper-[0-9][0-9] \
			p5-Devel-DProf-[0-9]* p5-Devel-Peek-[0-9]* \
			perl-mk-[0-9]*

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde
CONFIGURE_ARGS+=	-Dprefix="${PREFIX}"
CONFIGURE_ARGS+=	-Darchname="${MACHINE_ARCH}-${LOWER_OPSYS}"
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
CONFIGURE_ARGS+=	-Dcc="${CC}"
CONFIGURE_ARGS+=	-Uusemymalloc
CONFIGURE_ARGS+=	-Uinstallusrbinperl

.include "../../mk/bsd.prefs.mk"

MKPIC?=			yes

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.
#
LIBSWANTED.NetBSD=	m crypt

# SYSLIBPATH should contain the directories in which the system libraries
# may be found.
#
SYSLIBPATH.NetBSD=	/usr/lib
#SYSLIBPATH.Linux=	/lib /usr/lib

.if defined(LIBSWANTED.${OPSYS})
CONFIGURE_ARGS+=	-Dlibswanted="${LIBSWANTED.${OPSYS}}"
.endif

.if (${OPSYS} == "NetBSD")
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
MKPIC=			no
.endif
.if (${MACHINE_ARCH} == "sparc64")
# The toolchain on sparc64 is not really production-quality right now, but
# gcc-2.96 is supposed to fix most problems.  Passing -g to the configure
# process triggers -DDEBUGGING, which plays the real trick and circumvents
# code-generation bugs, so we add -g to CFLAGS to at least have a really
# debuggable build.
#
CFLAGS+=		-g -msoft-quad-float -O2
.endif
.elif (${OPSYS} == "SunOS")
CFLAGS=
.endif

.if (${MKPIC} == "yes")
CONFIGURE_ARGS+=	-Duseshrplib
.endif

PERL5_ARCHLIB=		${PREFIX}/lib/perl5/${PERL5_DIST_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_SITEARCH=		${PREFIX}/lib/perl5/site_perl/${PERL5_DIST_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_PACKLIST=		${PERL5_ARCHLIB}/.packlist

# It's tough to guess which hints file will be used, so add our modifications
# to all of them.
#
post-patch:
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		${CHMOD} +w $${hints};					\
		( ${ECHO} "";						\
		  ${ECHO} "locincpth=''";				\
		  ${ECHO} "loclibpth=''";				\
		) >> $${hints};						\
	done
.if defined(SYSLIBPATH.${OPSYS})
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		( ${ECHO} "glibpth='${SYSLIBPATH.${OPSYS}}'";		\
		) >> $${hints};						\
	done
.endif

# On platforms that build shared libraries, rebuild the perl binary as a
# statically linked binary for speed optimization.  Performance increase
# is only by word-of-mouth -- no actual benchmarks have been produced.
#
.if (${MKPIC} == "yes")
STATIC_WRKDIR=		${WRKDIR}/static
STATIC_MAKEFLAGS=	MKPIC=no
STATIC_MAKEFLAGS+=	WRKDIR=${STATIC_WRKDIR}
STATIC_MAKEFLAGS+=	ALL_TARGET=perl

post-build:
	cd ${.CURDIR} && ${MAKE} build ${STATIC_MAKEFLAGS}
.endif

post-install:
.if (${MKPIC} == "yes")
	${RM} ${PREFIX}/bin/perl
	${INSTALL_PROGRAM} ${STATIC_WRKDIR}/${DISTNAME}/perl ${PREFIX}/bin/perl
.endif
	strip ${PREFIX}/bin/a2p
	strip ${PREFIX}/bin/perl
	${RMDIR} -p ${PERL5_SITEARCH} 2>/dev/null || ${TRUE}
	${RM} -f ${WRKDIR}/bsd.perl.mk
	eval `${PERL5} -V:installsitelib 2>/dev/null` && \
		echo PERL5_SITELIB=$$installsitelib >>${WRKDIR}/bsd.perl.mk     
	eval `${PERL5} -V:installsitearch 2>/dev/null` && \
		echo PERL5_SITEARCH=$$installsitearch >>${WRKDIR}/bsd.perl.mk   
	eval `${PERL5} -V:installarchlib 2>/dev/null` && \
		echo PERL5_ARCHLIB=$$installarchlib >>${WRKDIR}/bsd.perl.mk     
	${INSTALL_DATA} ${WRKDIR}/bsd.perl.mk ${PREFIX}/share/mk/bsd.perl.mk

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} test

.include "../../mk/bsd.pkg.mk"
