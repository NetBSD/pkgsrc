# $Id: unexport.mk,v 1.2 2015/05/19 22:01:19 joerg Exp $

# pick up a bunch of exported vars
.include "export.mk"

.unexport UT_ZOO UT_FOO

UT_TEST = unexport
