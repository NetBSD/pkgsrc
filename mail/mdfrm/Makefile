# $NetBSD: Makefile,v 1.11 2006/01/21 18:57:41 jlam Exp $
#

DISTNAME=	mdfrm.pl
PKGNAME=	mdfrm-1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.goof.com/~mmead/
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Print a summary of mail in a Maildir waiting to be read

DEPENDS+=       p5-TimeDate-[0-9]*:../../time/p5-TimeDate

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
	${INSTALL_SCRIPT} ${WRKSRC}/mdfrm.pl ${PREFIX}/bin/mdfrm

.include "../../mk/bsd.pkg.mk"
