# $NetBSD: Makefile,v 1.24 2004/10/03 00:12:52 tv Exp $

DISTNAME=		cyrus-imapd-2.1.15
PKGREVISION=		4
SVR4_PKGNAME=		cimap
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/imap/

MAINTAINER=		chris@NetBSD.org
HOMEPAGE=		http://asg.web.cmu.edu/cyrus/imapd/
COMMENT=		Cyrus IMAP server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
PERL5_CONFIGURE=	no
USE_DB185=		no
AUTOCONF_REQD=		2.13

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

CONFIGURE_ARGS+=	--with-cyrus-user=${CYRUS_USER}
CONFIGURE_ARGS+=	--with-cyrus-group=${CYRUS_GROUP}
CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-statedir=/var/run
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ENV+=		ac_cv_lib_wrap_request_init=yes

CONFIGURE_ARGS+=	--enable-netscapehack
CONFIGURE_ARGS+=	--without-notify
CONFIGURE_ARGS+=	--without-ucdsnmp
CONFIGURE_ARGS+=	--without-zephyr

# Ensure that we use the db3 library, even if the db4 one gets pulled in
# as an indirect dependency.
#
.include "../../databases/db3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-bdb-libdir=${BUILDLINK_PREFIX.db3}/lib
CONFIGURE_ARGS+=	--with-bdb-incdir=${BUILDLINK_PREFIX.db3}/include/db3
.for _var_ in db_4_1 db4_1 db41 db_4_0 db4_0 db_4 db40 db4
CONFIGURE_ENV+=		ac_cv_lib_${_var_}_db_create=no
.endfor

.if defined(CYRUS_USE_INET6)
PKG_DEFAULT_OPTIONS+=	inet6
.endif
.if defined(CYRUS_DB_RECOMMENDED)
PKG_DEFAULT_OPTIONS+=	recommended-db
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-imapd
PKG_SUPPORTED_OPTIONS=	gssapi inet6 kerberos kerberos4 recommended-db
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	${DISTNAME}-ipv6-20030819.diff.gz
.endif

.if !empty(PKG_OPTIONS:Mrecommended-db)
#
# Follow the recommended methods for database types to use.  I'm not
# 100% ready to override the defaults till I've checked any side effects
# - chris@nb.org
#
CONFIGURE_ARGS+=	--with-duplicate-db=db3_nosync
CONFIGURE_ARGS+=	--with-mboxlist-db=skiplist
CONFIGURE_ARGS+=	--with-seen-db=skiplist
CONFIGURE_ARGS+=	--with-subs-db=flat
CONFIGURE_ARGS+=	--with-tls-db=db3_nosync
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=	gssapi
.  endif
.endif

.if !empty(PKG_OPTIONS:Mkerberos4)
.  if exists(/usr/include/kerberosIV/krb.h)
CRYPTO+=		uses Kerberos encryption code
CONFIGURE_ARGS+=	--with-auth=krb
CONFIGURE_ARGS+=	--with-krb=/usr
.  endif
.elif !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-auth=unix
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
CONFIGURE_ENV+=		COMPILE_ET=${KRB5BASE}/bin/compile_et
COMERRBASE=		${KRB5BASE}
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

# Change references of some manpages from foo.8 to cyrus-foo.8 to avoid
# manpage conflicts with other packages.  Also change references to
# "/etc/{cyrus,imapd}.conf" into "${PKG_SYSCONFDIR}/{cyrus,imapd}.conf".
#
post-patch:
	cd ${WRKSRC}/man;						\
	set --	deliver 8 imapd 8 master 8 pop3d 8;			\
	while [ $$# -gt 0 ]; do						\
		man=$$1.$$2;						\
		for file in Makefile.in *.[0-9]; do			\
			${SED}	-e "s|\(\$$(srcdir)/\)\($$man\)|\1cyrus-\2|g" \
				-e "s|\(\\\fB\)\($$1($$2)\\\fR\)|\1cyrus-\2|g" \
				$$file > $$file.fixed;			\
			${MV} -f $$file.fixed $$file;			\
		done;							\
		if [ -f $$man ]; then					\
			${MV} $$man cyrus-$$man;			\
		fi;							\
		shift 2;						\
	done
	${FIND} ${WRKSRC} -type f -print |				\
	${XARGS} -n 1 ${GREP} -l -e /etc/imapd\.conf -e /etc/cyrus\.conf | \
	while read file; do						\
		${SED}	-e "s|/etc/\(cyrus\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
			-e "s|/etc/\(imapd\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

pre-configure:
	cd ${WRKSRC} && ${AUTOHEADER} && ${AUTOCONF}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${PREFIX}/cyrus/bin
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

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
