# $NetBSD: Makefile,v 1.2 2019/10/24 20:47:14 nia Exp $

DISTNAME=	aspell6-nds-0.01-0
PKGNAME=	${DISTNAME:S/^aspell6/aspell/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/nds/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Low Saxon language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/aspell/iso-8859-15*

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
