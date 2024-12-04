/*
 * Copyright (C) 1989-95 GROUPE BULL
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * GROUPE BULL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of GROUPE BULL shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization from GROUPE BULL.
 */

/*****************************************************************************\
* rgb.c:                                                                      *
*                                                                             *
*  XPM library                                                                *
*  Rgb file utilities                                                         *
*                                                                             *
*  Developed by Arnaud Le Hors                                                *
\*****************************************************************************/

/*
 * Part of this code has been taken from the ppmtoxpm.c file written by Mark
 * W. Snitily but has been modified for my special need
 */

/* $NetBSD: rgb.c,v 1.1 2024/12/04 10:40:37 nros Exp $ */

#include "rgb.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Read a rgb text file.  It stores the rgb values (0->65535)
 * and the rgb mnemonics (malloc'ed) into the "rgbn" array.  Returns the
 * number of entries stored.
 */
int
pm_xpmReadRgbNames(
    const char	*rgb_fname,
    xpmRgbName	 rgbn[])
{
    FILE *rgbf;
    int n, items, red, green, blue;
    char line[512], name[512], *rgbname, *s1, *s2;
    xpmRgbName *rgb;

    /* Open the rgb text file.  Abort if error. */
    if ((rgbf = fopen(rgb_fname, FOPEN_RES)) == NULL)
	return 0;

    /* Loop reading each line in the file. */
    n = 0;
    rgb = rgbn;
    /* Quit if rgb text file has too many entries. */
    while (fgets(line, sizeof(line), rgbf) && n < MAX_RGBNAMES) {

	/* Skip silently if line is bad. */
	items = sscanf(line, "%d %d %d %[^\n]\n", &red, &green, &blue, name);
	if (items != 4)
	    continue;

	/*
	 * Make sure rgb values are within 0->255 range. Skip silently if
	 * bad.
	 */
	if (red < 0 || red > 0xFF ||
	    green < 0 || green > 0xFF ||
	    blue < 0 || blue > 0xFF)
	    continue;

	/* Allocate memory for ascii name. If error give up here. */
	if (!(rgbname = (char *) malloc(strlen(name) + 1)))
	    break;

	/* Copy string to ascii name and lowercase it. */
	for (s1 = name, s2 = rgbname; *s1; s1++)
	    *s2++ = tolower(*s1);
	*s2 = '\0';

	/* Save the rgb values and ascii name in the array. */
	rgb->r = red * 257;		/* 65535/255 = 257 */
	rgb->g = green * 257;
	rgb->b = blue * 257;
	rgb->name = rgbname;
	rgb++;
	n++;
    }

    fclose(rgbf);

    /* Return the number of read rgb names. */
    return n < 0 ? 0 : n;
}

/*
 * Return the color name corresponding to the given rgb values
 */
char *
pm_xpmGetRgbName(
    xpmRgbName	rgbn[],		/* rgb mnemonics from rgb text file */
    int		rgbn_max,	/* number of rgb mnemonics in table */
    int		red,		/* rgb values */
    int		green,
    int		blue)
{
    int i;
    xpmRgbName *rgb;

    /*
     * Just perform a dumb linear search over the rgb values of the color
     * mnemonics.  One could speed things up by sorting the rgb values and
     * using a binary search, or building a hash table, etc...
     */
    for (i = 0, rgb = rgbn; i < rgbn_max; i++, rgb++)
	if (red == rgb->r && green == rgb->g && blue == rgb->b)
	    return rgb->name;

    /* if not found return NULL */
    return NULL;
}

/*
 * Free the strings which have been malloc'ed in xpmReadRgbNames
 */
void
pm_xpmFreeRgbNames(
    xpmRgbName	rgbn[],
    int		rgbn_max)
{
    int i;
    xpmRgbName *rgb;

    for (i = 0, rgb = rgbn; i < rgbn_max; i++, rgb++)
	free(rgb->name);
}
