# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:44 jlam Exp $
#

DISTNAME=	tdir-1.58
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Display directories with files ordered by ending "extension"

DEPENDS+=	python-[0-9]*:../../lang/python

LICENSE=	tdir-license

post-patch:
	${SED} "s,/usr/local/bin/python,${LOCALBASE}/bin/python,"		\
		${WRKSRC}/tdir > ${WRKSRC}/tdir.done
	${MV} -f ${WRKSRC}/tdir.done ${WRKSRC}/tdir

.include "../../mk/bsd.pkg.mk"
