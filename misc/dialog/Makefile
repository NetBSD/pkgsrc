# $NetBSD: Makefile,v 1.19 2003/09/27 17:07:37 grant Exp $

DISTNAME=       dialog-0.6z
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_SUNSITE:=utils/shell/}

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Display dialog boxes from shell scripts

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]* NetBSD-1.6[A-P]-*

EGDIR=			${PREFIX}/share/examples/dialog
EGFILES=		checklist guage infobox inputbox menubox msgbox
EGFILES+=		radiolist textbox yesno

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/samples; for file in ${EGFILES}; do		\
		${MV} $${file} $${file}.tmp;				\
		${SED} "s|\.\./dialog|${PREFIX}/bin/dialog|g"		\
			$${file}.tmp > $${file};			\
		${RM} $${file}.tmp;					\
		${INSTALL_SCRIPT} $${file} ${EGDIR};			\
	done

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
