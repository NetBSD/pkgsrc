# $NetBSD: Makefile,v 1.46 2004/04/25 01:12:39 wiz Exp $

DISTNAME=		cyrus-imapd-2.0.17
PKGREVISION=		3
SVR4_PKGNAME=		cimap
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/imap/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://asg.web.cmu.edu/cyrus/imapd/
COMMENT=		Cyrus IMAP server

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
PERL5_CONFIGURE=	NO
AUTOCONF_REQD=		2.13

USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

.include "../../mk/bsd.prefs.mk"

.if defined(CYRUS_USE_INET6) && ${CYRUS_USE_INET6} == "YES"
PATCH_SITES=		http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=		${DISTNAME}-ipv6-20021205.diff.gz
.endif

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP
FILES_SUBST+=		CYRUS_USER=${CYRUS_USER}
FILES_SUBST+=		CYRUS_GROUP=${CYRUS_GROUP}

CONFIGURE_ARGS+=	--with-cyrus-user=${CYRUS_USER}
CONFIGURE_ARGS+=	--with-cyrus-group=${CYRUS_GROUP}
CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-statedir=/var/run
CONFIGURE_ARGS+=	--with-dbdir=${BUILDLINK_PREFIX.db3}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--without-ucdsnmp
CONFIGURE_ARGS+=	--without-notify
CONFIGURE_ARGS+=	--without-zephyr
CONFIGURE_ARGS+=	--enable-netscapehack

CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ENV+=		ac_cv_lib_wrap_request_init=yes

.if exists(/usr/include/krb5/com_err.h)
CPPFLAGS+=		-I/usr/include/krb5
CONFIGURE_ARGS+=	--with-com_err=
.else
CONFIGURE_ARGS+=	--with-com_err=yes
.endif

.if defined(KERBEROS) && ${KERBEROS} == 4
PKG_USE_KERBEROS=	# defined
CONFIGURE_ARGS+=	--with-auth=krb
.else
CONFIGURE_ARGS+=	--with-auth=unix
CONFIGURE_ARGS+=	--without-krb
.endif

HTMLDIR=		${PREFIX}/share/doc/html/cyrus-imapd
EGDIR=			${PREFIX}/share/examples/cyrus-imapd
CONF_FILES=		${EGDIR}/imapd.conf ${PKG_SYSCONFDIR}/imapd.conf
CONF_FILES+=		${EGDIR}/normal.conf ${PKG_SYSCONFDIR}/cyrus.conf
RCD_SCRIPTS=		cyrus
FILES_SUBST+=		IMAPDCONF=${PKG_SYSCONFDIR}/imapd.conf

PERL5_PACKLIST= \
	${PERL5_SITEARCH}/auto/Cyrus/IMAP/.packlist			\
	${PERL5_SITEARCH}/auto/Cyrus/SIEVE/acap/.packlist		\
	${PERL5_SITEARCH}/auto/Cyrus/SIEVE/managesieve/.packlist

# Change references of some manpages from foo.8 to cyrus-foo.8 to avoid
# manpage conflicts with other packages.  Also change references to
# "/etc/{cyrus,imapd}.conf" into "${PKG_SYSCONFDIR}/{cyrus,imapd}.conf".
#
post-patch:
	cd ${WRKSRC}/man;						\
	for file in deliver.8 imapd.8 master.8 pop3d.8; do		\
		${MV} $${file} cyrus-$${file};				\
		${SED}	-e "s|\(\$$(srcdir)/\)\($${file}\)|\1cyrus-\2|g" \
			Makefile.in > Makefile.in.fixed;		\
		${MV} -f Makefile.in.fixed Makefile.in;			\
	done
	files=`${FIND} ${WRKSRC} -type f -exec ${GREP} -l \
		-e /etc/imapd\.conf -e /etc/cyrus\.conf {} \;`; \
	for file in $${files}; do					\
		${SED}	-e "s|\(\\fB\)\($${name}($${suffix})\)|\1cyrus-\2|g" \
			-e "s|\(\$$(srcdir)/\)\($${man}\)|\1cyrus-\2|g"	\
			-e "s|/etc/\(cyrus\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
			-e "s|/etc/\(imapd\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

pre-configure:
	cd ${WRKSRC};							\
	${AUTOHEADER};							\
	${AUTOCONF}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${PREFIX}/cyrus/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf ${EGDIR}
	cd ${WRKSRC}/master/conf; ${INSTALL_DATA} *.conf ${EGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html cyrusv2.mc ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/man
	cd ${WRKSRC}/doc/man; ${INSTALL_DATA} *.html ${HTMLDIR}/man

.include "../../databases/db3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
