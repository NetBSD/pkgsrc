# $NetBSD: Makefile,v 1.22 2001/11/24 20:49:42 jlam Exp $

DISTNAME=		cyrus-imapd-2.0.16
SVR4_PKGNAME=		cimap
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/imap/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://asg.web.cmu.edu/cyrus/imapd/
COMMENT=		IMAP server

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP

CONFIGURE_ARGS+=	--with-cyrus-user=${CYRUS_USER}
CONFIGURE_ARGS+=	--with-cyrus-group=${CYRUS_GROUP}
CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-statedir=/var/run
CONFIGURE_ARGS+=	--with-dbdir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--without-ucdsnmp
CONFIGURE_ARGS+=	--without-notify
CONFIGURE_ARGS+=	--without-zephyr
CONFIGURE_ARGS+=	--enable-netscapehack

CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_DIR}
CONFIGURE_ENV+=		ac_cv_lib_wrap_request_init=yes

.if exists(/usr/include/krb5/com_err.h)
CPPFLAGS+=		-I/usr/include/krb5
CONFIGURE_ARGS+=	--with-com_err=
.else
CONFIGURE_ARGS+=	--with-com_err=yes
.endif

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=		# defined
CONFIGURE_ARGS+=	--with-auth=krb
.else
CONFIGURE_ARGS+=	--with-auth=unix
CONFIGURE_ARGS+=	--without-krb
.endif

LIBS+=			`${SASL_CONFIG} --libs`

HTMLDIR=		${PREFIX}/share/doc/html/cyrus-imapd
EGDIR=			${PREFIX}/share/examples/cyrus-imapd
CONF_FILES=		${EGDIR}/imapd.conf ${CONFDIR}/imapd.conf
CONF_FILES+=		${EGDIR}/normal.conf ${CONFDIR}/cyrus.conf
FILES_SUBST+=		IMAPDCONF=${CONFDIR}/imapd.conf

DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL
INSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL

PERL5_PACKLIST= \
	${PERL5_SITEARCH}/auto/Cyrus/IMAP/.packlist			\
	${PERL5_SITEARCH}/auto/Cyrus/SIEVE/acap/.packlist		\
	${PERL5_SITEARCH}/auto/Cyrus/SIEVE/managesieve/.packlist

# Change references of some manpages from foo.8 to cyrus-foo.8 to avoid
# manpage conflicts with other packages.  Also change references to
# "/etc/{cyrus,imapd}.conf" into "${CONFDIR}/{cyrus,imapd}.conf".
#
post-patch:
	cd ${WRKSRC}/man;						\
	for file in deliver.8 imapd.8 master.8 pop3d.8; do		\
		${MV} $${file} cyrus-$${file};				\
		${SED}	-e "s|\(\$$(srcdir)/\)\($${file}\)|\1cyrus-\2|g" \
			Makefile.in > Makefile.in.fixed;		\
		${MV} -f Makefile.in.fixed Makefile.in;			\
	done
	cd ${WRKSRC};							\
	files=`${FIND} . -type f -exec ${GREP} -l /etc/imapd\.conf {} \;`; \
	for file in $${files}; do					\
		${SED}	-e "s|\(\\fB\)\($${name}($${suffix})\)|\1cyrus-\2|g" \
			-e "s|\(\$$(srcdir)/\)\($${man}\)|\1cyrus-\2|g"	\
			-e "s|/etc/\(cyrus\.conf\)|${CONFDIR}/\1|g"	\
			-e "s|/etc/\(imapd\.conf\)|${CONFDIR}/\1|g"	\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${PREFIX}/cyrus/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf ${EGDIR}
	cd ${WRKSRC}/master/conf; ${INSTALL_DATA} *.conf ${EGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html cyrusv2.mc ${HTMLDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../databases/db3/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../security/cyrus-sasl/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
