/************** Machine (and compiler) dependent definitions. **************
 *
 *	Define appropriate types for the following ranges of integer
 *	variables.  These are processor & compiler dependent, but the
 *	distributed definitions will probably work on most systems.
 */



/*      MACHINE TYPE	DEFINED TYPE		VALUE RANGE	*/

typedef unsigned char	int8;		/*        0 ..     255 */
typedef short		int16;		/*  -10,000 ..  10,000 */
typedef long		int32;		/* -100,000 .. 100,000 */
typedef unsigned long	uint32;		/* 	  0 ..  2^31-1 */



/*
 *	Define NETWORK_BYTE_ORDER if the machine's longs are
 *	already in network byte order.
 */

#define NETWORK_BYTE_ORDER
