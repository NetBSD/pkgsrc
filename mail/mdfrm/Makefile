# $NetBSD: Makefile,v 1.4 2002/07/05 07:14:19 tron Exp $
#

DISTNAME=	mdfrm.pl
PKGNAME=	mdfrm-1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.goof.com/~mmead/
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@netbsd.org
COMMENT=	print a summary of mail in a Maildir waiting to be read

DEPENDS+=       p5-TimeDate-[0-9]*:../../time/p5-TimeDate

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
WRKSRC=		${WRKDIR}

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	${SED}	-e "s,/usr/local/bin/perl,${LOCALBASE}/bin/perl,g"	\
		-e "s,.Maildir,Maildir,g"				\
		${WRKSRC}/mdfrm.pl > ${WRKSRC}/mdfrm.pl.done
	${MV} ${WRKSRC}/mdfrm.pl.done ${WRKSRC}/mdfrm.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mdfrm.pl ${PREFIX}/bin/mdfrm

.include "../../mk/bsd.pkg.mk"
