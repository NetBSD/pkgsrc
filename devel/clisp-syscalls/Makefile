# $NetBSD: Makefile,v 1.4 2011/12/02 20:47:04 marino Exp $
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
