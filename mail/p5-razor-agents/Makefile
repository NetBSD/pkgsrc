# $NetBSD: Makefile,v 1.11 2003/09/27 13:20:25 heinz Exp $

DISTNAME=	razor-agents-2.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5ra
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=razor/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://razor.sourceforge.net/
COMMENT=	Distributed and collaborative spam detection network

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Digest-Nilsimsa-[0-9]*:../../security/p5-Digest-Nilsimsa
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

# because Net::Ping, Getopt::Long, File::Copy are needed
BUILDLINK_DEPENDS.perl=	perl>=5.6.0
USE_BUILDLINK2=		YES

PERL5_CONFIGURE=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/razor-agents/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
