# $NetBSD: Makefile,v 1.100 2013/11/13 13:34:32 joerg Exp $

DISTNAME=	cyrus-imapd-2.2.13p1
PKGREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/imap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cyrusimap.org/
COMMENT=	Cyrus IMAP server

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		perl
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PERL5_CONFIGURE=	no
BDB_ACCEPTED=		db3 db4 db5

.include "../../mk/bsd.prefs.mk"

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail

PKG_GROUPS_VARS+=	CYRUS_GROUP
PKG_USERS_VARS+=	CYRUS_USER
FILES_SUBST+=		CYRUS_USER=${CYRUS_USER}
FILES_SUBST+=		CYRUS_GROUP=${CYRUS_GROUP}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-cyrus-user=${CYRUS_USER}
CONFIGURE_ARGS+=	--with-cyrus-group=${CYRUS_GROUP}
CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-statedir=${VARBASE}/run
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ENV+=		ac_cv_lib_wrap_request_init=yes

CONFIGURE_ARGS+=	--enable-listext
CONFIGURE_ARGS+=	--enable-murder
CONFIGURE_ARGS+=	--enable-nntp
CONFIGURE_ARGS+=	--without-zephyr
CONFIGURE_ARGS+=	--without-ucdsnmp

CONFIGURE_ARGS+=	andrew_runpath_switch=${COMPILER_RPATH_FLAG}

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-imapd
PKG_SUPPORTED_OPTIONS=	gssapi kerberos kerberos4 ldap
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=	gssapi
.  endif
.endif

.if !empty(PKG_OPTIONS:Mkerberos4)
.  if exists(/usr/include/kerberosIV/krb.h)
CRYPTO+=		uses Kerberos encryption code
CONFIGURE_ARGS+=	--with-krb=/usr
.  endif
.elif !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
CONFIGURE_ENV+=		COMPILE_ET=${KRB5BASE}/bin/compile_et
.else
CONFIGURE_ARGS+=	--without-krb
CONFIGURE_ARGS+=	--disable-gssapi
CHECK_BUILTIN.heimdal:=		yes
.  include "../../security/heimdal/builtin.mk"
CHECK_BUILTIN.heimdal:=		no
CHECK_BUILTIN.mit-krb5:=	yes
.  include "../../security/mit-krb5/builtin.mk"
CHECK_BUILTIN.mit-krb5:=	no
.  if ( !empty(USE_BUILTIN.heimdal:M[Yy][Ee][Ss]) || \
	!empty(USE_BUILTIN.mit-krb5:M[Yy][Ee][Ss])) && \
        exists(/usr/bin/compile_et) && exists(/usr/include/krb5/com_err.h)
CPPFLAGS+=	-I/usr/include/krb5
CONFIGURE_ENV+=	COMPILE_ET=/usr/bin/compile_et
.  elif ${OPSYS} != "Linux" && \
	exists(/usr/bin/compile_et) && exists(/usr/include/com_err.h)
CONFIGURE_ENV+=	COMPILE_ET=/usr/bin/compile_et
.  else
CONFIGURE_ARGS+=	--with-com-err=yes
.  endif
.endif

PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
PLIST.ldap=		yes
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

# CYRUS_IDLE selects the method used to implement IMAP IDLE.  Valid values
# are "poll", "idled" or "no".  The default is "poll".
#
CYRUS_IDLE?=		poll
BUILD_DEFS+=		CYRUS_IDLE
PLIST_VARS+=		idled
.if (${CYRUS_IDLE} != "poll") && (${CYRUS_IDLE} != "idled") && \
    (${CYRUS_IDLE} != "no")
PKG_FAIL_REASON+=	"CYRUS_IDLE must be poll, idled or no"
.endif
CONFIGURE_ARGS+=	--with-idle=${CYRUS_IDLE:Q}
.if ${CYRUS_IDLE} == "idled"
PLIST.idled=		yes
.endif

MAKE_ENV+=		PERL=${PERL5:Q}

HTMLDIR=		${PREFIX}/share/doc/html/cyrus-imapd
EGDIR=			${PREFIX}/share/examples/cyrus-imapd
CONF_FILES=		${EGDIR}/imapd.conf ${PKG_SYSCONFDIR}/imapd.conf
CONF_FILES+=		${EGDIR}/normal.conf ${PKG_SYSCONFDIR}/cyrus.conf
RCD_SCRIPTS=		cyrus
FILES_SUBST+=		IMAPDCONF=${PKG_SYSCONFDIR}/imapd.conf

PERL5_PACKLIST= \
	auto/Cyrus/IMAP/.packlist			\
	auto/Cyrus/SIEVE/managesieve/.packlist

.include "../../lang/perl5/module.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

CONFIGURE_ENV+=	BDB_TYPE=${BDB_TYPE}

# Only imap/mupdate needs to be build with pthreads support, so selectively
# enable it via patches for just that one program.
#
.include "../../mk/pthread.buildlink3.mk"

# Change references of some manpages from foo.8 to cyrus-foo.8 to avoid
# manpage conflicts with other packages.  Also change references to
# "/etc/{cyrus,imapd}.conf" into "${PKG_SYSCONFDIR}/{cyrus,imapd}.conf".
#
post-patch:
	cd ${WRKSRC}/man;						\
	set --	deliver 8 fetchnews 8 idled 8 imapd 8 lmtpd 8 master 8	\
		nntpd 8	notifyd 8 pop3d 8 quota 8;			\
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
			$$file > $$file.fixed;				\
		${MV} -f $$file.fixed $$file;				\
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mknewsgroups ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/translatesieve ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/rehash ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/master/conf; for file in *.conf; do		\
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR};		\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/doc; for file in *.html cyrusv2.mc; do		\
		${INSTALL_DATA} $$file ${DESTDIR}${HTMLDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
