# $NetBSD: Makefile,v 1.7 2013/12/09 14:17:44 obache Exp $

DISTNAME=	IPC-DirQueue-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-DirQueue/
COMMENT=	Disk-based many-to-many task queue
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=  {perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IPC/DirQueue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
