# $NetBSD: application.mk,v 1.1 2019/08/18 03:44:42 maya Exp $
#
# Replace the #! interpreter for nodejs scripts.
#
# This mk fragment should be included in all node.js packages that
# install node scripts, or at least those that don't use setuptools
# or some other mechanism to set the real path.  Specifically, it is
# reasonable to include both egg.mk and application.mk.
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
