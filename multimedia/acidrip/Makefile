# $NetBSD: Makefile,v 1.6 2005/07/13 18:01:34 jlam Exp $
#

DISTNAME=	acidrip-0.14
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acidrip/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://untrepid.com/acidrip/
COMMENT=	Gtk2::Perl application for ripping and encoding DVDs

DEPENDS+=	lsdvd-[0-9]*:../../multimedia/lsdvd
DEPENDS+=	mencoder-[0-9]*:../../multimedia/mencoder
DEPENDS+=	mplayer-[0-9]*:../../multimedia/mplayer
DEPENDS+=	p5-gtk2>=1.040:../../x11/p5-gtk2

USE_PERL5=	yes

PERL5_REQD=     5.8
PERL5_PACKLIST= auto/AcidRip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
