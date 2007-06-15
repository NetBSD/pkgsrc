# $NetBSD: Makefile,v 1.40 2007/06/15 18:15:18 jlam Exp $

DISTNAME=	maildrop-2.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.courier-mta.org/maildrop/

PKG_DESTDIR_SUPPORT=	user-destdir

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
SPECIAL_PERMS=	bin/lockmail ${REAL_ROOT_USER} ${COURIER_GROUP} 755
SPECIAL_PERMS+=	bin/maildrop ${REAL_ROOT_USER} ${COURIER_GROUP} 4555

.include "../../devel/sysexits/buildlink3.mk"

INSTALLATION_DIRS=	${DOCDIR}/maildrop

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildrop/maildroptips.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildrop/README.html ${DESTDIR}${DOCDIR}/maildrop
	${INSTALL_DATA} ${WRKSRC}/maildrop/makedat.html ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/maildrop/makedat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
