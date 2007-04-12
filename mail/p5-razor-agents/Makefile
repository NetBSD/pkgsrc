# $NetBSD: Makefile,v 1.26 2007/04/12 20:23:30 heinz Exp $

DISTNAME=	razor-agents-2.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FLAGS+=	MANSUBDIR=${PKGMANDIR:Q}

PERL5_PACKLIST=	auto/razor-agents/.packlist
REPLACE_PERL+=	lib/Razor2/*.pm  lib/Razor2/*/*.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
