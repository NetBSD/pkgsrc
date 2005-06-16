# $NetBSD: Makefile,v 1.105 2005/06/16 06:58:03 jlam Exp $

DISTNAME=	pine4.62
PKGNAME=	pine-4.62
PKGREVISION=	2
CATEGORIES=	mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Program for Internet News and E-mail

LICENSE=	pine-license

USE_PKGINSTALL=		yes

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

.if !empty(CC_VERSION:Mgcc-*)
UNLIMIT_RESOURCES+=	datasize
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.pine
PKG_SUPPORTED_OPTIONS=	ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
PINE_LDAPCFLAGS=	LDAPCFLAGS="-DENABLE_LDAP"
PINE_LDAPLIBS=		LDAPLIBS="-lldap -llber"
.endif

INSTALLATION_DIRS=	bin man/man1

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
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rpdump ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rpload ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pine
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/rpdump.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/rpload.1 ${PREFIX}/man/man1
	( ${ECHO} '# (This file is not part of the pine distribution! - HF)' ; \
	  ${PREFIX}/bin/pine -conf ) | ${SED} \
	    -e 's|^\(use-only-domain-name\)=.*$$|\1=No|g' \
	    -e 's|^\(feature-list\)=.*$$|\1=enable-mail-check-cue,enable-suspend,expanded-view-of-addressbooks,include-header-in-reply,include-text-in-reply,show-selected-in-boldface,signature-at-bottom|g' \
	    -e 's|^\(sort-key\)=.*$$|\1=Arrival/Reverse|g' \
	    >${PREFIX}/share/examples/pine/pine.conf
	${INSTALL_DATA}	${FILESDIR}/pine.conf.fixed ${PREFIX}/share/examples/pine/
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine/contrib
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine/contrib/utils
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${PREFIX}/share/pine/
	${INSTALL_DATA} ${WRKSRC}/contrib/krb5-setup ${PREFIX}/share/pine/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/ldap-setup ${PREFIX}/share/pine/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/utils/* ${PREFIX}/share/pine/contrib/utils
	${CHMOD} +x ${PREFIX}/share/pine/contrib/utils/*.sh

.include "../../devel/ncurses/buildlink3.mk"
.include "../../editors/pico/buildlink3.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
