# $NetBSD: Makefile,v 1.3 2002/11/29 01:27:39 markd Exp $

DISTNAME=	yafc-0.7.10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yafc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@netbsd.org
HOMEPAGE=	http://yafc.sourceforge.net/
COMMENT=	Yet another FTP client

GNU_CONFIGURE=		yes
USE_GNU_READLINE=	yes
USE_BUILDLINK2=		yes

CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
INFO_FILES=		yafc.info

.include "../../mk/bsd.prefs.mk"

.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=        --with-krb5 --with-krb5-include=/usr/include/krb5
CPPFLAGS+=		-I/usr/include/gssapi
.endif

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
