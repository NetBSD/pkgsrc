# $NetBSD: Makefile,v 1.21 2001/11/21 22:12:24 wiz Exp $

DISTNAME=		cyrus-imapd-2.0.16
SVR4_PKGNAME=		cimap
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/imap/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://asg.web.cmu.edu/cyrus/imapd/
COMMENT=		IMAP server

DEPENDS+=		cyrus-sasl>=1.5.24nb2:../../security/cyrus-sasl
DEPENDS+=		db3>=2.9:../../databases/db3

USE_PERL5=		# defined
USE_SSL=		# defined
GNU_CONFIGURE=		# defined

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
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-dbdir=${LOCALBASE}
CONFIGURE_ARGS+=	--without-ucdsnmp
CONFIGURE_ARGS+=	--without-notify
CONFIGURE_ARGS+=	--without-zephyr
CONFIGURE_ARGS+=	--enable-netscapehack

.if exists(/usr/include/krb5/com_err.h)
CONFIGURE_ARGS+=	--with-com_err=/usr
CPPFLAGS+=		-I/usr/include/krb5
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

LIBS+=			`sasl-config --libs`

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

HTMLDIR=		${PREFIX}/share/doc/html/cyrus-imapd
EGDIR=			${PREFIX}/share/examples/cyrus-imapd

PERL5_PACKLIST= \
	${PERL5_SITEARCH}/auto/Cyrus/IMAP/.packlist \
	${PERL5_SITEARCH}/auto/Cyrus/SIEVE/acap/.packlist \
	${PERL5_SITEARCH}/auto/Cyrus/SIEVE/managesieve/.packlist

# Change references of some manpages from foo.8 to cyrus-foo.8 to avoid
# manpage conflicts with other packages.
#
post-patch:
	cd ${WRKSRC}/man;						\
	for man in deliver.8 imapd.8 master.8 pop3d.8; do		\
		${MV} $${man} cyrus-$${man};				\
		name=$${man%.*};					\
		suffix=$${man##*.};					\
		for file in *.[0-9]*; do				\
			${SED} -e "s|\(\\fB\)\($${name}($${suffix})\)|\1cyrus-\2|g" \
				$${file} > $${file}.fixed;		\
			${MV} -f $${file}.fixed $${file};		\
		done;							\
		${SED} -e "s|\(\$$(srcdir)/\)\($${man}\)|\1cyrus-\2|g"	\
			Makefile.in > Makefile.in.fixed;		\
		${MV} -f Makefile.in.fixed Makefile.in;			\
	done

pre-install:
	${SED}	-e "s,@AWK@,${AWK},g" \
		-e "s,@CAT@,${CAT},g" \
		-e "s,@RM@,${RM},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@CAT@,${CAT},g" \
		-e "s,@CHMOD@,${CHMOD},g" \
		-e "s,@CP@,${CP},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${PREFIX}/cyrus/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf ${EGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html cyrusv2.mc ${HTMLDIR}
	cd ${WRKSRC}/master/conf; ${INSTALL_DATA} *.conf ${EGDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
