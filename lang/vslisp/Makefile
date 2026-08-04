# $NetBSD: Makefile,v 1.24 2026/08/04 20:29:04 wiz Exp $

DISTNAME=	vslisp-4.0-1
PKGNAME=	vslisp-4.0.1
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vslisp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vslisp.sourceforge.net/
COMMENT=	Embeddable Lisp library and standalone interpreter

# funcs.c:153:17: error: use of undeclared identifier 'r'
# funct.c:336:15: error: expected expression
# and similar
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/vslisp-4.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vslisp
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vslisp/html
	@for d in Colors.txt ColorsDemo.txt lisp.sgml ; do \
		${INSTALL_DATA} ${WRKSRC}/Documentation/$$d \
		${DESTDIR}${PREFIX}/share/doc/vslisp; done
	${INSTALL_DATA} ${WRKSRC}/Documentation/html/* \
		${DESTDIR}${PREFIX}/share/doc/vslisp/html

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
