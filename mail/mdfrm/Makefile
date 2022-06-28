# $NetBSD: Makefile,v 1.25 2022/06/28 11:34:22 wiz Exp $
#

DISTNAME=	mdfrm.pl
PKGNAME=	mdfrm-1.0
PKGREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	http://www.goof.com/~mmead/
EXTRACT_SUFX=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Print a summary of mail in a Maildir waiting to be read

DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

post-patch:
	${SED}	-e "s,/usr/local/bin/perl,${LOCALBASE}/bin/perl,g"	\
		-e "s,.Maildir,Maildir,g"				\
		${WRKSRC}/mdfrm.pl > ${WRKSRC}/mdfrm.pl.done
	${MV} ${WRKSRC}/mdfrm.pl.done ${WRKSRC}/mdfrm.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mdfrm.pl ${DESTDIR}${PREFIX}/bin/mdfrm

.include "../../mk/bsd.pkg.mk"
