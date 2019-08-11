# $NetBSD: Makefile,v 1.40 2019/08/11 13:22:37 wiz Exp $

PKGNAME=		revbump-2.14
PKGREVISION=		2
CATEGORIES=		pkgtools

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		Tools for bumping PKGREVISIONs (for pkgsrc developers)
LICENSE=		modified-bsd

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
USE_TOOLS+=	perl:run
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

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

.include "../../mk/bsd.pkg.mk"
