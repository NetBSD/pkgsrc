# $NetBSD: Makefile,v 1.1.1.1 2003/09/28 11:04:28 xtraeme Exp $
#

DISTNAME=	sylpheed-0.9.5-gtk2-20030906
PKGNAME=	sylpheed-gtk2-0.9.5
CATEGORIES=	mail x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-gtk2/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.homa.ne.jp/~ashie/linux/sylpheed-gtk2.html
COMMENT=	The GTK+ 2.0 port of a lightweight, featureful, and fast e-mail client

BUILD_USES_MSGFMT=      yes
DEPENDS+=               metamail>=2.7:../../mail/metamail

CONFLICTS=      	sylpheed-claws-[0-9]* sylpheed-[0-9]*

USE_BUILDLINK2=         yes
USE_PKGINSTALL=         yes
USE_PKGLOCALEDIR=       yes
USE_X11=                yes
USE_GMAKE=              yes

GNU_CONFIGURE=          yes
CONFIGURE_ARGS+=        --enable-nls
CONFIGURE_ARGS+=        --enable-ssl
CONFIGURE_ARGS+=        --enable-gpgme
CONFIGURE_ARGS+=        --enable-compface

PKG_SYSCONFSUBDIR=      sylpheed
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=            USE_INET6 USE_OPENLDAP USE_JPILOT

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=        --enable-ipv6
.endif

FACES_IS_INSTALLED!=    ${PKG_INFO} -e faces || ${ECHO}
.if empty(FACES_IS_INSTALLED)
.  include "../../graphics/compface/buildlink2.mk"
.else
.  include "../../mail/faces/buildlink2.mk"
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
CONFIGURE_ARGS+=        --enable-ldap
.include "../../databases/openldap/buildlink2.mk"
.endif

.if defined(USE_JPILOT) && ${USE_JPILOT} == YES
CONFIGURE_ARGS+=        --enable-jpilot
.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../comms/jpilot/buildlink2.mk"
.endif

EGDIR=          ${PREFIX}/share/examples/sylpheed
CONF_FILES=     ${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/mime.types ${EGDIR}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/gpgme/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
