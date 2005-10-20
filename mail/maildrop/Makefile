# $NetBSD: Makefile,v 1.27 2005/10/20 20:26:37 jlam Exp $

DISTNAME=	maildrop-2.0.1
PKGBASE=	${DISTNAME:C/-[^-]*$//}
CATEGORIES=     security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.courier-mta.org/maildrop/

DEPENDS+=	courier-maildir>=0.52.1:../../mail/courier-maildir

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKG_SUPPORTED_OPTIONS=	authlib
PKG_SUGGESTED_OPTIONS=	authlib

.include "../../mail/courier-maildir/Makefile.common"
.include "../../security/courier-authlib/Makefile.common"

# These are the users that may invoke maildrop with the "-d user"
# argument (mailbox delivery mode).
#
MAILDROP_TRUSTED_USERS?=	${ROOT_USER} ${COURIER_USER} qmaild

CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-maildirquota
CONFIGURE_ARGS+=	--enable-maildrop-uid=${ROOT_USER}
CONFIGURE_ARGS+=	--enable-maildrop-gid=${COURIER_GROUP}
CONFIGURE_ARGS+=	--enable-trusted-users='${MAILDROP_TRUSTED_USERS}'
CONFIGURE_ARGS+=	--enable-trusted-groups='${COURIER_GROUP}'
CONFIGURE_ARGS+=	--enable-syslog=1

.if !empty(PKG_OPTIONS:Mauthlib)
CONFIGURE_ARGS+=	--enable-authlib
.  include "../../security/courier-authlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-authlib
.endif

SPECIAL_PERMS=	bin/maildrop ${ROOT_USER} ${COURIER_GROUP} 4711

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildroptips.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
