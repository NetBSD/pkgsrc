# $NetBSD: Makefile,v 1.5 2019/03/17 11:28:13 rillig Exp $
#

DISTNAME=	subst-19.03
CATEGORIES=	regress
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test the SUBST framework
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
USE_TOOLS+=	diff printf

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-build
SUBST_FILES.vars=	vars.after
SUBST_VARS.vars=	PLAIN DQUOT SQUOT DELIM PRINTABLE
SUBST_VARS.vars+=	UNDEFINED
SUBST_VARS.vars+=	BETWEEN_SPACE BETWEEN_TAB BETWEEN_NL
SUBST_VARS.vars+=	BACKSLASHES VAR...... VAR.abcde

PLAIN=		hello_world
DQUOT=		"hello   world"
SQUOT=		'hello     world'
DELIM=		hello,  world
PRINTABLE=	!"\#$$%&'()*+,-./09:;<=>?@AZ[\]^_`az{|}

#UNDEFINED=	# undefined

# Ensure that leading and trailing whitespace is preserved.
BETWEEN_SPACE=	${:U }between spaces${:U }
BETWEEN_TAB=	${:U	}between tabs${:U	}
# TODO: currently fails; needs to be fixed in subst.mk
#BETWEEN_NL=	${.newline}between newlines${.newline}

BACKSLASHES=	\" \, \\, \" \' \0\000 \x40 \089 \a \$$

# Ensure that special regex characters may appear in variable names.
VAR......=	dots
VAR.abcde=	letters

do-extract:
	${RUN} ${SED} -e /^\#/d -e /^$$/d ${FILESDIR}/expected \
	> ${WRKSRC}/expected

pre-build:
	${RUN} printf '%s: <@%s@>\n' ${SUBST_VARS.vars:@var@ ${var:Q} ${var:Q} @} \
	> ${WRKSRC}/vars.before
	${RUN} ${CAT} ${WRKSRC}/vars.before > ${WRKSRC}/vars.after

do-build:
	@${DO_NADA}

post-build:
	${RUN} diff -u ${WRKSRC}/expected ${WRKSRC}/vars.after

.include "../../mk/bsd.pkg.mk"
