# $NetBSD: Makefile,v 1.3 2004/10/03 00:12:52 tv Exp $
#

DISTNAME=		elmo-1.2.0
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=elmo/}

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://elmo.sourceforge.net/
COMMENT=		The ELectronic Mail Operator MUA

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

REPLACE_PERL=		elmoconf.pl

CONFIGURE_ARGS+=	--with-gpgme-prefix=${BUILDLINK_PREFIX.gpgme}

SUBST_CLASSES=		tux
SUBST_STAGE.tux=	post-patch
SUBST_FILES.tux=	configure
SUBST_SED.tux=		-e "s|==|=|"
SUBST_MESSAGE.tux=	"Fixing linuxifications."

.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
