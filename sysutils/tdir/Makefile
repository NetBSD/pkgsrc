# $NetBSD: Makefile,v 1.2 2001/07/07 09:29:30 zuntum Exp $
#

DISTNAME=	tdir-1.58
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Display directories with files ordered by ending "extension"

DEPENDS+=	python-*:../../lang/python

LICENSE=	tdir-license

post-patch:
	${SED} "s,/usr/local/bin/python,${LOCALBASE}/bin/python,"		\
		${WRKSRC}/tdir > ${WRKSRC}/tdir.done
	${MV} -f ${WRKSRC}/tdir.done ${WRKSRC}/tdir

.include "../../mk/bsd.pkg.mk"
