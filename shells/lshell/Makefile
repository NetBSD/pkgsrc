# $NetBSD: Makefile,v 1.8 2012/03/09 12:34:22 wiz Exp $
#

DISTNAME=	lshell-0.9.14
PKGREVISION=	1
CATEGORIES=	shells python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lshell/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://ghantoos.org/limited-shell-lshell/
COMMENT=	Lshell restricts user's environment to specified commands
LICENSE=	gnu-gpl-v3

PKG_GROUPS=	lshellg
PKG_SHELL=	bin/lshell

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none

PYDISTUTILSPKG=		yes

EGDIR=			share/examples/lshell

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	lshellmodule/lshell.py

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,/etc,${EGDIR},'
SUBST_SED.setup+=	-e 's,share/man,${PKGMANDIR},'

INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/logrotate.d ${PKGMANDIR}/man1

CONF_FILES=		${PREFIX}/${EGDIR}/lshell.conf \
			${PKG_SYSCONFDIR}/lshell.conf

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
