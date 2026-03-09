# $NetBSD: Makefile,v 1.1 2026/03/09 03:07:49 jnemeth Exp $

DISTNAME=	cyrus-imapd-3.10.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=cyrusimap/}
GITHUB_TAG=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cyrusimap.org/
COMMENT=	Cyrus IMAP server
LICENSE=	original-bsd # like license

MAKE_JOBS_SAFE=	no

USE_TOOLS+=		perl:run makedepend pkg-config gmake bison bash:run
USE_TOOLS+=		autoconf automake autoreconf
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PERL5_CONFIGURE=	no
USE_LIBTOOL=		yes

BUILD_DEFS+=		VARBASE

CHECK_PORTABILITY_SKIP=	configure.lineno

.include "../../mk/bsd.prefs.mk"

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP
FILES_SUBST+=		CYRUS_USER=${CYRUS_USER}
FILES_SUBST+=		CYRUS_GROUP=${CYRUS_GROUP}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-cyrus-user=${CYRUS_USER}
#CONFIGURE_ARGS+=	--with-cyrus-group=${CYRUS_GROUP}
#CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/cyrus-master.pid
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ENV+=		ac_cv_lib_wrap_request_init=yes

CONFIGURE_ARGS+=	--enable-idled
CONFIGURE_ARGS+=	--enable-murder
CONFIGURE_ARGS+=	--enable-nntp
CONFIGURE_ARGS+=	--enable-replication

CONFIGURE_ARGS+=	andrew_cv_runpath_switch=${COMPILER_RPATH_FLAG}

.include "options.mk"

MAKE_ENV+=		PERL=${PERL5:Q}

HTMLDIR=		${PREFIX}/share/doc/cyrus-imapd
EGDIR=			${PREFIX}/share/examples/cyrus-imapd
CONF_FILES=		${EGDIR}/imapd.conf ${PKG_SYSCONFDIR}/imapd.conf
CONF_FILES+=		${EGDIR}/normal.conf ${PKG_SYSCONFDIR}/cyrus.conf
RCD_SCRIPTS=		cyrus
FILES_SUBST+=		IMAPDCONF=${PKG_SYSCONFDIR}/imapd.conf

REPLACE_BASH+=		imap/cyr_cd.sh

REPLACE_PERL+=		imap/promdatagen
REPLACE_PERL+=		perl/annotator/Daemon.pm
REPLACE_PERL+=		perl/sieve/scripts/sieveshell.pl
REPLACE_PERL+=		snmp/snmpgen
REPLACE_PERL+=		tools/config2header
REPLACE_PERL+=		tools/masssievec
REPLACE_PERL+=		tools/mkimap
REPLACE_PERL+=		tools/mknewsgroups
REPLACE_PERL+=		tools/rehash

# Override default Perl install location
SUBST_CLASSES+=		perldir
SUBST_STAGE.perldir=	post-configure
SUBST_FILES.perldir=	perl/annotator/Makefile
SUBST_FILES.perldir+=	perl/imap/Makefile
SUBST_FILES.perldir+=	perl/sieve/managesieve/Makefile
SUBST_SED.perldir+=	-e 's|\(^INSTALLDIRS =\) .*|\1 vendor|'

PERL5_PACKLIST= \
	auto/Cyrus/Annotator/Daemon/.packlist		\
	auto/Cyrus/IMAP/.packlist			\
	auto/Cyrus/SIEVE/managesieve/.packlist

post-extract:
#	set -e; cd ${WRKSRC} && automake -acf
	set -e; cd ${WRKSRC} && autoreconf -fi

#pre-build:
#	${RUN}${_ULIMIT_CMD} \
#	cd ${WRKSRC} && ${BUILD_MAKE_CMD} depend

.include "../../lang/perl5/module.mk"
BUILDLINK_API_DEPENDS.cyrus-sasl+=	cyrus-sasl>=2.1.17
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

# Only imap/mupdate needs to be build with pthreads support, so selectively
# enable it via patches for just that one program.
#
.include "../../mk/pthread.buildlink3.mk"

# XXX cyrus imapd no longer comes with prebuilt man pages
# # Change references of some manpages from foo.8 to cyrus-foo.8 to avoid
# # manpage conflicts with other packages.  Also change references to
# # "/etc/{cyrus,imapd}.conf" into "${PKG_SYSCONFDIR}/{cyrus,imapd}.conf".
# #
# post-patch:
#	cd ${WRKSRC}/man;						\
#	set --	deliver 8 fetchnews 8 idled 8 imapd 8 lmtpd 8 master 8	\
#		nntpd 8	notifyd 8 pop3d 8 quota 8;			\
#	while [ $$# -gt 0 ]; do						\
#		man=$$1.$$2;						\
#		for file in Makefile.in *.[0-9]; do			\
#			sed	-e "s|\(\$$(srcdir)/\)\($$man\)|\1cyrus-\2|g" \
#				-e "s|\(\\\fB\)\($$1($$2)\\\fR\)|\1cyrus-\2|g" \
#				$$file > $$file.fixed;			\
#			mv -f $$file.fixed $$file;			\
#		done;							\
#		if [ -f $$man ]; then					\
#			mv $$man cyrus-$$man;			\
#		fi;							\
#		shift 2;						\
#	done
#	find ${WRKSRC} -type f -print |					\
#	xargs -n 1 ${GREP} -l -e /etc/imapd\.conf -e /etc/cyrus\.conf | \
#	while read file; do						\
#		sed	-e "s|/etc/\(cyrus\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
#			-e "s|/etc/\(imapd\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
#			$${file} > $${file}.fixed;			\
#		mv -f $${file}.fixed $${file};			\
#	done

post-install:
#	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec ${DESTDIR}${PREFIX}/sbin
#	${INSTALL_SCRIPT} ${WRKSRC}/tools/migrate-metadata ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mknewsgroups ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/translatesieve ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/rehash ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/doc/examples/cyrus_conf; for file in *.conf; do		\
		${INSTALL_DATA} $${file} ${DESTDIR}${EGDIR};		\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
#	cd ${WRKSRC}/doc/legacy; for file in *.html cyrusv2.mc; do		\
	cd ${WRKSRC}/doc/legacy; for file in *.html; do		\
		${INSTALL_DATA} $${file} ${DESTDIR}${HTMLDIR};		\
	done

.include "../../time/libical/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3}
.include "../../mk/bsd.pkg.mk"
