# $NetBSD: Makefile,v 1.15 2004/11/12 00:26:03 seb Exp $

DISTNAME=	razor-agents-2.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	# empty
SVR4_PKGNAME=	p5ra
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=razor/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://razor.sourceforge.net/
COMMENT=	Distributed and collaborative spam detection network

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# because Net::Ping, Getopt::Long, File::Copy are needed
PERL5_REQD+=		5.6.0
USE_BUILDLINK3=		YES

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/razor-agents/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
