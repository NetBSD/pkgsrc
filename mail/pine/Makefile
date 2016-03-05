# $NetBSD: Makefile,v 1.134 2016/03/05 11:28:50 jperkin Exp $

DISTNAME=	pine4.64
PKGNAME=	pine-4.64
PKGREVISION=	13
CATEGORIES=	mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Program for Internet News and E-mail
LICENSE=	pine-license

CONF_FILES=    ${PREFIX}/share/examples/pine/pine.conf ${PKG_SYSCONFDIR}/pine.conf

.include "../../mk/compiler.mk"

.if ${OPSYS} == "SunOS"
BUILDNAME=	so5
BUILDFILE=	sol
.elif ${OPSYS} == "Linux"
BUILDNAME=	lnx
BUILDFILE=	lnx
.elif ${OPSYS} == "Darwin"
BUILDNAME=	osx
BUILDFILE=	osx
LIBS+=		-lcurses
.elif ${OPSYS} == "IRIX"
.  if ${OS_VERSION} >= 6.5
BUILDNAME=	sg6
.  else
BUILDNAME=	sgi
.  endif
BUILDFILE=	sgi
.else
BUILDNAME=	neb
BUILDFILE=	neb
.endif

BUILDLINK_TRANSFORM.OpenBSD+=	rm:-lcrypt

.if !empty(CC_VERSION:Mgcc-*)
UNLIMIT_RESOURCES+=	datasize
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.pine
PKG_SUPPORTED_OPTIONS=	ldap fancythreads pinepwd
PKG_SUGGESTED_OPTIONS=	pinepwd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
PINE_LDAPCFLAGS=	LDAPCFLAGS="-DENABLE_LDAP"
PINE_LDAPLIBS=		LDAPLIBS="-lldap -llber"
.endif

.if !empty(PKG_OPTIONS:Mfancythreads)
PATCH_SITES+=		http://staff.washington.edu/chappa/pine/patches/pine4.64/
PATCHFILES+=		fancy.patch.gz
PATCH_DIST_STRIP=	-p1
.endif

.if !empty(PKG_OPTIONS:Mpinepwd)
CFLAGS+=		-DPASSFILE=\\\".pinepwd\\\"
.endif

REPLACE_PERL+=		contrib/utils/pwd2pine

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 \
			share/examples/pine share/pine/contrib/utils

# Make sure the imap lib that comes with pine isn't
# used (see http://www.securityfocus.com/advisories/2646)
pre-patch:
	${RM} -fr ${WRKSRC}/imap

do-configure:
	${CP} -f ${WRKSRC}/pine/osdep/os-${BUILDFILE}.h ${WRKSRC}/pine/osdep/os-${BUILDFILE}.h.orig
	${SED} \
		-e 's@/usr/local/lib/@${PKG_SYSCONFDIR}/@' \
		-e 's@DEFAULT_DEBUG.*2@DEFAULT_DEBUG 0@' \
		<${WRKSRC}/pine/osdep/os-${BUILDFILE}.h.orig >${WRKSRC}/pine/osdep/os-${BUILDFILE}.h
	@${RM} -rf ${WRKSRC}/pico
	@${LN} -sf ${BUILDLINK_DIR}/include/pico ${WRKSRC}/pico

do-build:
	cd ${WRKSRC} && ${_ULIMIT_CMD} 					\
	${SETENV} ${MAKE_ENV} ./build ${BUILDNAME}			\
		${PINE_LDAPCFLAGS} ${PINE_LDAPLIBS}			\
		PREFIX=${PREFIX}					\
		CC="${CC} ${CFLAGS}"					\
		EXTRALDFLAGS="${LDFLAGS} ${LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rpdump ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rpload ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/rpdump.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/rpload.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	( ${ECHO} '# (This file is not part of the pine distribution! - HF)' ; \
	  ${DESTDIR}${PREFIX}/bin/pine -conf ) | ${SED} \
	    -e 's|^\(use-only-domain-name\)=.*$$|\1=No|g' \
	    -e 's|^\(feature-list\)=.*$$|\1=enable-mail-check-cue,enable-suspend,expanded-view-of-addressbooks,include-header-in-reply,include-text-in-reply,show-selected-in-boldface,signature-at-bottom|g' \
	    -e 's|^\(sort-key\)=.*$$|\1=Arrival/Reverse|g' \
	    >${DESTDIR}${PREFIX}/share/examples/pine/pine.conf
	${INSTALL_DATA}	${FILESDIR}/pine.conf.fixed ${DESTDIR}${PREFIX}/share/examples/pine/
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${DESTDIR}${PREFIX}/share/pine/
	${INSTALL_DATA} ${WRKSRC}/contrib/krb5-setup ${DESTDIR}${PREFIX}/share/pine/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/ldap-setup ${DESTDIR}${PREFIX}/share/pine/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/utils/* ${DESTDIR}${PREFIX}/share/pine/contrib/utils
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/pine/contrib/utils/*.sh

# 2004e contains extensions needed by Pine 4.63
BUILDLINK_API_DEPENDS.imap-uw+=	imap-uw>=2004e
.include "../../mail/imap-uw/buildlink3.mk"

.include "../../mk/terminfo.buildlink3.mk"
.include "../../editors/pico/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
