# $NetBSD: Makefile,v 1.7 2004/04/25 07:38:20 snj Exp $

DISTNAME=	yafc-0.7.10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yafc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://yafc.sourceforge.net/
COMMENT=	Yet another FTP client

GNU_CONFIGURE=		yes
USE_GNU_READLINE=	yes
USE_BUILDLINK3=		yes

CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
INFO_FILES=		yafc.info

.include "../../mk/bsd.prefs.mk"

.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=        --with-krb5 --with-krb5-include=/usr/include/krb5
CPPFLAGS+=		-I/usr/include/gssapi
.endif

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
