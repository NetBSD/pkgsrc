# $NetBSD: Makefile,v 1.23 2011/08/14 13:25:22 obache Exp $

DISTNAME=	grepmail-5.3033
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grepmail/}

MAINTAINER=	david@fundy.net
HOMEPAGE=	http://grepmail.sourceforge.net/
COMMENT=	mbox formatted file search utility

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-Mail-Mbox-MessageParser>=1.4001:../../mail/p5-Mail-Mbox-MessageParser

PERL5_PACKLIST=	auto/grepmail/.packlist
MAKE_PARAMS+=	< /dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
