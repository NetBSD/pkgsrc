# $NetBSD: Makefile,v 1.3 2012/09/11 23:19:39 asau Exp $
#

DISTNAME=	pkgsrc-todo-1.1
CATEGORIES=	pkgtools
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Tools for maintaing pkgsrc/doc/TODO

DEPENDS+=	p5-pkgsrc-Dewey-[0-9]*:../../pkgtools/p5-pkgsrc-Dewey

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:build

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		todo
SUBST_STAGE.todo=	post-configure
SUBST_FILES.todo+=	add_todo.pl
SUBST_FILES.todo+=	add_todo.1
SUBST_FILES.todo+=	obsolete_todo.pl
SUBST_FILES.todo+=	obsolete_todo.1
SUBST_SED.todo+=	-e s\|@PKGSRCDIR@\|${PKGSRCDIR}\|g
SUBST_SED.todo+=	-e s\|pkgsrc/\|${PKGSRCDIR}/\|g
SUBST_SED.todo+=	-e s\|@PERL@\|${PERL5:Q}\|g

do-extract:
	cd ${FILESDIR} && ${CP} add_todo.1 add_todo.pl obsolete_todo.1 \
		obsolete_todo.pl ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/add_todo.pl \
		${DESTDIR}${PREFIX}/bin/add_todo
	${INSTALL_SCRIPT} ${WRKSRC}/obsolete_todo.pl \
		${DESTDIR}${PREFIX}/bin/obsolete_todo
	${INSTALL_MAN} ${WRKSRC}/add_todo.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/obsolete_todo.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
