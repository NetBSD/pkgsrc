#!/bin/sh
# $Id: endian.sh,v 1.1 2001/09/02 23:04:23 kristerw Exp $
# Trivial script to output BIG_ENDIAN or LITTLE_ENDIAN
printf '#include <machine/endian.h>\n#if BYTE_ORDER == BIG_ENDIAN\nORDER_BIG_ENDIAN\n#else\nORDER_LITTLE_ENDIAN\n#endif\n' | cpp -P | sed -n 's/^ORDER_//p'
