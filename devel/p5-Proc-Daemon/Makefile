# $NetBSD: Makefile,v 1.11 2008/06/12 02:14:25 joerg Exp $
#

DISTNAME=	Proc-Daemon-0.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5prd
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.mhonarc.org/~ehood/earlsperls.html
COMMENT=	Provide capability for a Perl program to run as a daemon

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Proc/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
