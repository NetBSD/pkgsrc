#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

/* #include <wx/wxchar.h> */

bool
wxStringMatch2 (const wxChar *str1, const wxChar *str2, bool subString, bool exact)
{
  if (str1 == NULL || str2 == NULL)
    return FALSE;
  if (str1 == str2)
    return TRUE;

  if (subString)
    {
      int len1 = wxStrlen (str1);
      int len2 = wxStrlen (str2);
      int i;

      // Search for str1 in str2
      // Slow .... but acceptable for short strings
      for (i = 0; i <= len2 - len1; i++)
        {
          if (wxStrnicmp (str1, str2 + i, len1) == 0)
            return TRUE;
        }
    }
  else if (exact)
    {
      if (wxStricmp (str1, str2) == 0)
        return TRUE;
    }
  else
    {
      int len1 = wxStrlen (str1);
      int len2 = wxStrlen (str2);

      if (wxStrnicmp (str1, str2, wxMin (len1, len2)) == 0)
        return TRUE;
    }

  return FALSE;
}
