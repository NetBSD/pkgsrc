# $NetBSD: Makefile,v 1.37 2006/07/11 00:57:43 joerg Exp $

DISTNAME=	maildrop-2.0.2
CATEGORIES=     security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.courier-mta.org/maildrop/

DEPENDS+=	courier-maildir>=0.53.1:../../mail/courier-maildir

USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++

PKG_SUPPORTED_OPTIONS=	authlib
PKG_SUGGESTED_OPTIONS=	authlib

# PKGNAME is a parameter to the following file.
PKGNAME=	${DISTNAME}
.include "../../mail/courier-mta/Makefile.common"

# These are the users that may invoke maildrop with the "-d user"
# argument (mailbox delivery mode).
#
MAILDROP_TRUSTED_USERS?=	${ROOT_USER} ${COURIER_USER} qmaild

CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-maildirquota
CONFIGURE_ARGS+=	--enable-maildrop-uid=${ROOT_USER:Q}
CONFIGURE_ARGS+=	--enable-maildrop-gid=${COURIER_GROUP:Q}
CONFIGURE_ARGS+=	--enable-trusted-users=${MAILDROP_TRUSTED_USERS:Q}
CONFIGURE_ARGS+=	--enable-trusted-groups=${COURIER_GROUP:Q}
CONFIGURE_ARGS+=	--enable-syslog=1

.if !empty(PKG_OPTIONS:Mauthlib)
CONFIGURE_ARGS+=	--enable-authlib
.  include "../../security/courier-authlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-authlib
.endif

REQD_DIRS=	${DOCDIR}
SPECIAL_PERMS=	bin/maildrop ${ROOT_USER} ${COURIER_GROUP} 4711

.include "../../devel/sysexits/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildrop/maildroptips.html ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/maildrop
	${INSTALL_DATA} ${WRKSRC}/maildrop/README.html ${DOCDIR}/maildrop
	${INSTALL_DATA} ${WRKSRC}/maildrop/makedat.html ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/maildrop/makedat.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
