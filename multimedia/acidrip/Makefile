# $NetBSD: Makefile,v 1.1.1.1 2004/04/20 22:58:57 xtraeme Exp $
#

DISTNAME=	acidrip-0.12
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acidrip/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://acidrip.thirtythreeandathird.net/
COMMENT=	Gtk2::Perl application for ripping and encoding DVDs

DEPENDS+=	lsdvd-[0-9]*:../../multimedia/lsdvd
DEPENDS+=	mencoder-[0-9]*:../../multimedia/mencoder
DEPENDS+=	mplayer-[0-9]*:../../multimedia/mplayer
DEPENDS+=	p5-gtk2>=1.040:../../x11/p5-gtk2

USE_BUILDLINK3=	yes
USE_PERL5=	yes

PERL5_REQD=     5.8
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/AcidRip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
