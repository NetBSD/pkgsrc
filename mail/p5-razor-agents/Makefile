# $NetBSD: Makefile,v 1.23 2006/07/15 12:38:39 heinz Exp $

DISTNAME=	razor-agents-2.82
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ra
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=razor/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://razor.sourceforge.net/
COMMENT=	Distributed and collaborative spam detection network

# Net::Ping, Getopt::Long, File::Copy are also needed (from the perl package)
DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/razor-agents/.packlist
CHECK_INTERPRETER_SKIP+=${PERL5_INSTALLVENDORARCH}/Razor2/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
