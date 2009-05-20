# $NetBSD: Makefile,v 1.17 2009/05/20 00:58:26 wiz Exp $

DISTNAME=	yafc-0.7.10
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yafc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yafc.sourceforge.net/
COMMENT=	Yet another FTP client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_GNU_READLINE=	yes

CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-krb5 --with-krb5-include=/usr/include/krb5
CPPFLAGS+=		-I/usr/include/gssapi
LIBS+=			-lcrypt -lcrypto
.endif

.include "../../devel/readline/buildlink3.mk"
.if defined(KERBEROS)
.include "../../mk/krb5.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
