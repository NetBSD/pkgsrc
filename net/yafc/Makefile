# $NetBSD: Makefile,v 1.1.1.1 2002/06/25 02:12:40 markd Exp $

DISTNAME=	yafc-0.7.8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yafc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@netbsd.org
HOMEPAGE=	http://yafc.sourceforge.net/
COMMENT=	Yet another FTP client

GNU_CONFIGURE=		yes
USE_GNU_READLINE=	yes
USE_BUILDLINK_ONLY=	yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_DIR}
.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=        --with-krb5 --with-krb5-include=/usr/include/krb5
CPPFLAGS+=		-I/usr/include/gssapi
.endif

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
