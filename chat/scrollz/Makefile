# $NetBSD: Makefile,v 1.31 2020/05/22 10:55:58 adam Exp $

DISTNAME=	ScrollZ-2.2.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	9
CATEGORIES=	chat
MASTER_SITES=	http://www.scrollz.info/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.scrollz.info/
COMMENT=	Advanced IRC client based on ircII client
LICENSE=	modified-bsd # XXX ?

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		mandir
SUBST_FILES.mandir=	Makefile.in
SUBST_MESSAGE.mandir=	Fixing PKGMANDIR path.
SUBST_SED.mandir=	-e 's|@prefix@/share/man/man1|@mandir@/man1|1'
SUBST_STAGE.mandir=	pre-configure

.include "options.mk"

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/scrollz.1

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
