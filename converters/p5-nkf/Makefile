# $NetBSD: Makefile,v 1.14 2005/08/06 06:19:05 jlam Exp $
#

DISTNAME=	nkf205
PKGNAME=	p5-nkf-2.05
SVR4_PKGNAME=	p5nkf
PKGREVISION=	1
CATEGORIES=	japanese converters perl5
MASTER_SITES=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/nkf/
COMMENT=	Perl library for Network Kanji code conversion Filter

WRKSRC=			${WRKDIR}/${DISTNAME}/NKF.mod
PERL5_PACKLIST=		auto/NKF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
