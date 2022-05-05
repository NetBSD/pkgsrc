# $NetBSD: application.mk,v 1.2 2022/05/05 13:06:50 gutteridge Exp $
#
# Replace the #! interpreter for node.js scripts.
#
# This mk fragment should be included in all node.js packages that
# install node scripts.
#
# Package-settable variables:
#
# REPLACE_NODEJS
#	A list of node scripts to be installed, relative to ${WRKSRC}.
#
# Keywords: node node.js nodejs
#
.if defined(REPLACE_NODEJS)
REPLACE_INTERPRETER+=	nodejs
REPLACE.nodejs.old=	.*node
REPLACE.nodejs.new=	${PREFIX}/bin/node
REPLACE_FILES.nodejs=	${REPLACE_NODEJS}
.endif
