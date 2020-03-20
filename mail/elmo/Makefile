# $NetBSD: Makefile,v 1.34 2020/03/20 11:57:57 nia Exp $
#

DISTNAME=		elmo-1.3.2
PKGREVISION=		19
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=elmo/}

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://elmo.sourceforge.net/
COMMENT=		The ELectronic Mail Operator MUA

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		flex perl:run
GNU_CONFIGURE=		yes

REPLACE_PERL=		src/elmoconf.pl

CONFIGURE_ARGS+=	--with-gpgme-prefix=${BUILDLINK_PREFIX.gpgme}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
# I get segmentation faults when not compiled with debug enabled
CONFIGURE_ARGS+=	--enable-debug

.include "../../mk/curses.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
