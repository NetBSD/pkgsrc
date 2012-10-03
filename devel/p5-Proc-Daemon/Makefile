# $NetBSD: Makefile,v 1.17 2012/10/03 21:55:31 wiz Exp $
#

DISTNAME=	Proc-Daemon-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5prd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mhonarc.org/~ehood/earlsperls.html
COMMENT=	Provide capability for a Perl program to run as a daemon

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Proc/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
