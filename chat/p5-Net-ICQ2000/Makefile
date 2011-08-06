# $NetBSD: Makefile,v 1.15 2011/08/06 13:11:26 adam Exp $

DISTNAME=	Net-ICQ2000-0.2.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	chat perl5
MASTER_SITES=	http://gonzo.kiev.ua/projects/vicq.old/
#		${MASTER_SITE_SOURCEFORGE:=neticq2k/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gonzo.kiev.ua/projects/vicq.old/
COMMENT=	Perl5 modules for the ICQv7 protocol realisation

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/ICQ2000/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
