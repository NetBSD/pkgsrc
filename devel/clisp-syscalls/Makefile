# $NetBSD: Makefile,v 1.3 2011/04/20 18:57:22 hans Exp $
#

CLISP_MODULE=	syscalls

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP, a Common Lisp implementation

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

post-patch:
	(cd ${WRKSRC} && ${CP} -p src/gllib/mbrtowc.c modules/syscalls/gllib)
	
.include "../../mk/bsd.pkg.mk"
