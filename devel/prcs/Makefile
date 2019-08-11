# $NetBSD: Makefile,v 1.57 2019/08/11 13:20:49 wiz Exp $

DISTNAME=		prcs-1.3.3
PKGREVISION=		14
CATEGORIES=		devel scm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=prcs/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://prcs.sourceforge.net/
COMMENT=		Project Revision Control System
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		lispdir=${PREFIX}/share/examples/prcs
INFO_FILES=		yes
USE_LANGUAGES=		c c++
BUILD_DEFS+=		VARBASE
CONFIGURE_ENV+=		EMACS=no
CONFIGURE_ENV+=		PRCS_REPOSITORY=${VARBASE:Q}/PRCS
CONFIGURE_ENV+=		SYS_GDIFF_COMMAND_PATH=${TOOLS_DIFF:Q}
CONFIGURE_ENV+=		SYS_GZIP_COMMAND_PATH=${TOOLS_GZIP_CMD:Q}
CONFIGURE_ENV+=		SYS_TAR_COMMAND_PATH=${TOOLS_TAR:Q}
CONFIGURE_ENV+=		SYS_LS_COMMAND_PATH=${TOOLS_LS:Q}
USE_TOOLS+=		diff:run gzip:run ls:run tar:run perl:run

REPLACE_INTERPRETER+=	perl5
REPLACE.perl5.old=	.*perl[^[:space:]]*
REPLACE.perl5.new=	${PERL5}
REPLACE_FILES.perl5=	emacs/prcs-ediff emacs/prcs-emerge

.include "../../mk/bsd.pkg.mk"
