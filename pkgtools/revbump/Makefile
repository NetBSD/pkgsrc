# $NetBSD: Makefile,v 1.50 2023/05/26 06:47:54 wiz Exp $

PKGNAME=		revbump-3.0
CATEGORIES=		pkgtools

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.pkgsrc.org/
COMMENT=		Tool for bumping PKGREVISIONs (for pkgsrc developers)
LICENSE=		modified-bsd AND 2-clause-bsd

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

REPLACE_PYTHON+=	revbump.py

post-extract:
	${CP} ${FILESDIR}/revbump.py ${WRKSRC}

do-configure:

do-build:
.for  i in  blbump finddepends revbump replace-commonbump check-cvs-diff
	${SED} -e "s!@PERL@!${PERL5}!g" -e "s! make ! ${MAKE} !g" \
		${FILESDIR}/${i} > ${WRKDIR}/${i}
.endfor

do-install:
.for  i in  blbump finddepends revbump replace-commonbump check-cvs-diff
	${INSTALL_SCRIPT} ${WRKDIR}/${i} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/${i}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/revbump.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/revbump.py.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
