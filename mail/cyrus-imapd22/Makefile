# $NetBSD: Makefile,v 1.8 2004/04/20 15:54:02 recht Exp $

DISTNAME=	cyrus-imapd-2.2.3
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/imap/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://asg.web.cmu.edu/cyrus/imapd/
COMMENT=	Cyrus IMAP server

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PERL5_CONFIGURE=	no
USE_DB185=		no
BDB_ACCEPTED=		db4 db3

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

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
CONFIGURE_ARGS+=	--with-cyrus-group=${CYRUS_GROUP}
CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-statedir=/var/run
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ENV+=		ac_cv_lib_wrap_request_init=yes

CONFIGURE_ARGS+=	--enable-listext
CONFIGURE_ARGS+=	--enable-murder
CONFIGURE_ARGS+=	--enable-nntp
CONFIGURE_ARGS+=	--without-zephyr
CONFIGURE_ARGS+=	--without-ucdsnmp

.if defined(KERBEROS)
.  if (${KERBEROS} == 4) && exists(/usr/include/kerberosIV/krb.h)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-auth=krb
CONFIGURE_ARGS+=	--with-krb=/usr
.  else
.    include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-auth=krb5
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
CONFIGURE_ENV+=		COMPILE_ET=${KRB5BASE}/bin/compile_et
COMERRBASE=		${KRB5BASE}
.  endif
.else
CONFIGURE_ARGS+=	--with-auth=unix
CONFIGURE_ARGS+=	--without-krb
CONFIGURE_ARGS+=	--disable-gssapi
.endif

.if exists(/usr/bin/compile_et)
COMERRBASE?=		/usr
.endif
.if defined(COMERRBASE)
.  if exists(${COMERRBASE}/include/krb5/com_err.h)
CPPFLAGS+=		-I${COMERRBASE}/include/krb5
.  endif
CONFIGURE_ENV+=		COMPILE_ET=${COMERRBASE}/bin/compile_et
.else
CONFIGURE_ARGS+=	--with-com-err=yes
.endif

MAKEFLAGS+=		PERL=${PERL5}

HTMLDIR=		${PREFIX}/share/doc/html/cyrus-imapd
EGDIR=			${PREFIX}/share/examples/cyrus-imapd
CONF_FILES=		${EGDIR}/imapd.conf ${PKG_SYSCONFDIR}/imapd.conf
CONF_FILES+=		${EGDIR}/normal.conf ${PKG_SYSCONFDIR}/cyrus.conf
RCD_SCRIPTS=		cyrus
FILES_SUBST+=		IMAPDCONF=${PKG_SYSCONFDIR}/imapd.conf

PERL5_PACKLIST= \
	${PERL5_SITEARCH}/auto/Cyrus/IMAP/.packlist			\
	${PERL5_SITEARCH}/auto/Cyrus/SIEVE/managesieve/.packlist

.include "../../lang/perl5/module.mk"
.include "../../security/cyrus-sasl2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

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

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec ${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mknewsgroups ${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/translatesieve ${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/rehash ${PREFIX}/cyrus/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf ${EGDIR}
	cd ${WRKSRC}/master/conf; for file in *.conf; do		\
		${INSTALL_DATA} $$file ${EGDIR};			\
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; for file in *.html cyrusv2.mc; do		\
		${INSTALL_DATA} $$file ${HTMLDIR};			\
	done

.include "../../mk/bsd.pkg.mk"
