#ifndef _STRINGMATCH_H_
#define _STRINGMATCH_H_
#include "wx/object.h"
#include "wx/list.h"
#include "wx/filefn.h"

WXDLLEXPORT bool wxStringMatch2(const wxChar *one, const wxChar *two, bool subString = TRUE, bool exact = FALSE);
#endif // _STRINGMATCH_H_
