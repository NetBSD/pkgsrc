# $NetBSD: Makefile,v 1.13 2008/01/18 05:08:23 tnn Exp $
#

DISTNAME=		elmo-1.3.2
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=elmo/}

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://elmo.sourceforge.net/
COMMENT=		The ELectronic Mail Operator MUA

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		flex
GNU_CONFIGURE=		yes

REPLACE_PERL=		elmoconf.pl

CONFIGURE_ARGS+=	--with-gpgme-prefix=${BUILDLINK_PREFIX.gpgme}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
# I get segmentation faults when not compiled with debug enabled
CONFIGURE_ARGS+=	--enable-debug

SUBST_CLASSES+=		tux
SUBST_STAGE.tux=	post-patch
SUBST_FILES.tux=	configure
SUBST_SED.tux=		-e "s|==|=|"
SUBST_MESSAGE.tux=	Fixing linuxifications.

.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
