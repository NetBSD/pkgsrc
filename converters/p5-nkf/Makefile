# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:09 tv Exp $
#

DISTNAME=	nkf204
PKGNAME=	p5-nkf-2.04
SVR4_PKGNAME=	p5nkf
PKGREVISION=	1
CATEGORIES=	japanese converters perl5
MASTER_SITES=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/
COMMENT=	Perl library for Network Kanji code conversion Filter

WRKSRC=			${WRKDIR}/${DISTNAME}/NKF.mod
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/NKF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
